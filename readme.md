# 引言

嗨，这是一个使用了瀚文HelloWord固件的Dactyl人体工程学键盘，其继承了瀚文键盘的基本功能（按键、RGB灯效），支持热插拔，Dactyl生成器所生成的外壳。

为了最大程度适配瀚文固件所产生的一些设计，导致本项目的复刻难度可能较高，详细情况将在后续内容提及。

# 致谢、参考项目

非常感谢键盘爱好者的无私奉献，下面是本项目继承、参考的项目：

- [peng-zhihui-HelloWord-Keyboard](https://github.com/peng-zhihui/HelloWord-Keyboard)

  瀚文键盘

- [ibnuda-dactyl-keboard](https://github.com/ibnuda/dactyl-keyboard)

  dactyl外壳生成器

- [yejianfengblue-dactyl-generator-demo](https://github.com/yejianfengblue/dactyl-generator-demo)

  dactyl外壳生成器在各参数下的demo

# 文件结构

- 3Dmodel

  该目录下存放了3D模型文件，其中包括了dactyl外壳生成器的json配置文件、OpenSCAD源文件、用于固定PCB的SolidWorks工程文件以及最终导出，能够直接进行3D打印的STL文件。

- Firmware

  该目录下存放了修改后的瀚文键盘固件工程文件、固件（release文件夹下）。

- PCB

  该目录下存放了使用LCEDA绘制的PCB原理图、Layout，以及能够直接用于PCB制造的Gerber文件。

# 构建指南

## 电路构建

本项目的PCB一共包括三块：KeyBoard（轴、灯珠承载板），LeftBoard（左手PCB，其上有移位寄存器及MCU）、RightBoard（右手PCB，其上有移位寄存器）。

由于Dactyl的形状特殊，每个按键需要独立PCB的承载，并用FPC软排线进行互相连接，并最终接入LeftBoard、RightBoard。

待续......
