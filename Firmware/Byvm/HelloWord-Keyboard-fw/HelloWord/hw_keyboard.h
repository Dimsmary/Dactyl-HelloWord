#ifndef HELLO_WORD_KEYBOARD_FW_HW_KEYBOARD_H
#define HELLO_WORD_KEYBOARD_FW_HW_KEYBOARD_H

#include "spi.h"


class HWKeyboard
{
public:
    explicit HWKeyboard(SPI_HandleTypeDef* _spi) :
        spiHandle(_spi)
    {
        scanBuffer = &spiBuffer[1];

        // Enable 74HC165 clock
        HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET);
    }


    static const uint8_t IO_NUMBER = 11 * 8; // Used 11 pcs 74HC165
    static const uint8_t KEY_NUMBER = 82;
    static const uint8_t TOUCHPAD_NUMBER = 6;
    static const uint8_t LED_NUMBER = 104;
    static const uint8_t KEYMAP_NUM = 5;
    static const uint16_t KEY_REPORT_SIZE = 1 + 16;
    static const uint16_t RAW_REPORT_SIZE = 1 + 32;
    static const uint16_t HID_REPORT_SIZE = KEY_REPORT_SIZE + RAW_REPORT_SIZE;

    enum KeyCode_t : int16_t
    {
        /*------------------------- HID report data -------------------------*/
        LEFT_CTRL = -8, LEFT_SHIFT = -7, LEFT_ALT = -6, LEFT_GUI = -5,
        RIGHT_CTRL = -4, RIGHT_SHIFT = -3, RIGHT_ALT = -2, RIGHT_GUI = -1,

        RESERVED = 0, ERROR_ROLL_OVER, POST_FAIL, ERROR_UNDEFINED,
        A, B, C, D, E, F, G, H, I, J, K, L, M,
        N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        NUM_1/*1!*/, NUM_2/*2@*/, NUM_3/*3#*/, NUM_4/*4$*/, NUM_5/*5%*/,
        NUM_6/*6^*/, NUM_7/*7&*/, NUM_8/*8**/, NUM_9/*9(*/, NUM_0/*0)*/,
        ENTER, ESC, BACKSPACE, TAB, SPACE,
        MINUS/*-_*/, EQUAL/*=+*/, LEFT_U_BRACE/*[{*/, RIGHT_U_BRACE/*]}*/,
        BACKSLASH/*\|*/, NONE_US/**/, SEMI_COLON/*;:*/, QUOTE/*'"*/,
        GRAVE_ACCENT/*`~*/, COMMA/*,<*/, PERIOD/*.>*/, SLASH/*/?*/,
        CAP_LOCK, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        PRINT, SCROLL_LOCK, PAUSE, INSERT, HOME, PAGE_UP, DELETE, END, PAGE_DOWN,
        RIGHT_ARROW, LEFT_ARROW, DOWN_ARROW, UP_ARROW, PAD_NUM_LOCK,
        PAD_SLASH, PAD_ASTERISK, PAD_MINUS, PAD_PLUS, PAD_ENTER,
        PAD_NUM_1, PAD_NUM_2, PAD_NUM_3, PAD_NUM_4, PAD_NUM_5,
        PAD_NUM_6, PAD_NUM_7, PAD_NUM_8, PAD_NUM_9, PAD_NUM_0,
        PAD_PERIOD = 99, // followed with 20 bits 0, total 16 Bytes report data
        /*------------------------- HID report data -------------------------*/

//      /*-------------------------- Virtual keys ---------------------------*/
//      EXECUTE = 116,
//      HELP, MENU, SELECT, STOP, AGAIN, UNDO, CUT, COPY, PASTE, FIND, MUTE,
//      VOLUME_UP, VOLUME_DOWN,
//      /*-------------------------- Virtual keys ---------------------------*/

        /*--------------------------- Smart keys ----------------------------*/
        FN = 1000,
        TOUCH_BAR_1, TOUCH_BAR_2, TOUCH_BAR_3, TOUCH_BAR_4, TOUCH_BAR_5, TOUCH_BAR_6
        /*--------------------------- Smart keys ----------------------------*/
    };

    struct Color_t
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    enum SpiWs2812Byte_t : uint8_t
    {
        // This should be tuned considering WS2812b clock timing
        WS_HIGH = 0xFE,
        WS_LOW = 0xE0
    };


    uint8_t* ScanKeyStates();
    void ApplyDebounceFilter(uint32_t _filterTimeUs = 100);
    uint8_t* Remap(uint8_t _layer = 1);
    void SetRgbBuffer(uint8_t _keyId, Color_t _color);
    void SyncLights();
    bool FnPressed();
    uint8_t* GetHidReportBuffer(uint8_t _reportId = 0);


    int16_t keyMap[KEYMAP_NUM][IO_NUMBER] = {
        /*
        每行有几个数字，就代表左（右）板上的4、6FPC座之间要串几个轴板。例如 “//FPC2 to FPC11”这行就只有三个数字“5、6、7”，代表其连接顺序为 FPC12➡️ U3➡️U2➡️U1 ➡️FPC11。而每行数字，由左至右分别是U3、U2、U1。

        按键列表和IO列表，其排序对应键盘左上角由左往右，再由上往下。

        IO列表的排序方式是使用的“白雨木的连线方式”。
        */

        {/*第0层*/
            //右扩展板
            0 , 1 , 2 , 3 , //最左边没连按键的4个IO

            //FPC2  to FPC11 //FPC5  to FPC14
            26, 27, 28,      17, 18, 19, 
            //FPC6  to FPC1  //FPC4  to FPC13 
            29, 30, 31,      20, 21, 22, 
            //FPC3  to FPC12 //FPC10 to FPC18
            23, 24, 25,      5 , 6 , 7 , 
            //FPC8  to FPC16 //FPC7  to FPC15
            11, 12, 13,      14, 15, 16, 
            //FPC9  to FPC17
            8 , 9 , 10, 
            //FPC19
            4 , 


            //左主控板
            32, 33, 34, 35, //最左边没连按键的4个IO

            //FPC10 to FPC20 //FPC7  to FPC17
            61, 62, 63,      52, 53, 54, 
            //FPC9  to FPC19 //FPC8  to FPC18
            58, 59, 60,      55, 56, 57, 
            //FPC5  to FPC15 //FPC6  to FPC16
            46, 47, 48,      49, 50, 51, 
            //FPC3  to FPC13 //FPC4  to FPC14
            40, 41, 42,      43, 44, 45, 
            //FPC2  to FPC12
            37, 38, 39, 
            //FPC1  to FPC11
            36, 
        },

        /*
        第1层的按键布局列表，会对应其所在的位数，映射到第0层io位数
        */
        
        {/*第1层*/
            //右扩展板
            ESC, F1, F2, BACKSLASH, //最左边没连按键的4个IO
            NUM_6, NUM_7, NUM_8, NUM_9, NUM_0, EQUAL, 
            Y, U, I, O, P, MINUS,
            H, J, K, L, SEMI_COLON, QUOTE,
            N, M, COMMA, PERIOD, SLASH, RIGHT_SHIFT,
            LEFT_U_BRACE, RIGHT_U_BRACE, BACKSPACE, 
            ENTER, 
            
            //左主控板
            E, R, T, Y, //最左边没连按键的4个IO
            GRAVE_ACCENT, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5,
            TAB, Q, W, E, R, T, 
            CAP_LOCK, A, S, D, F, G, 
            LEFT_CTRL, Z, X, C, V, B, 
            SPACE, LEFT_GUI, ESC, 
            LEFT_ALT, 
        },

            /*
            {

            }
            */
    };

    volatile bool isRgbTxBusy{};
    uint8_t hidBuffer[HID_REPORT_SIZE]{};


private:
    SPI_HandleTypeDef* spiHandle;
    uint8_t spiBuffer[IO_NUMBER / 8 + 1]{};
    uint8_t* scanBuffer;
    uint8_t debounceBuffer[IO_NUMBER / 8 + 1]{};
    uint8_t remapBuffer[IO_NUMBER / 8]{};

    uint8_t rgbBuffer[LED_NUMBER][3][8]{};
    uint8_t wsCommit[64] = {0};
    uint8_t brightnessPrediv = 2; // means 1/4 brightness
};


#endif
