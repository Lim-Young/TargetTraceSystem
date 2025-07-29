# TargetTraceSystem
> Language: [English](README.md), [中文](README-CN.md)

一个通用的目标追踪系统，允许开发者能够集中管理各种目标追踪需求，特别适合用于敌人AI系统。

## 特性
- 事件驱动，对性能友好
- 模块化设计，易于扩展
- 支持自定义追踪器，以满足特定需求

## 使用方法
1. 添加`TargetTraceSystem`组件到你的Actor上。

    ![](Doc/Img/IMG_AddTargetTraceSystemComponent.png)

2. 配置`Target Tracers`字典，键为追踪器的名称，值为追踪器的实例。

    ![](Doc/Img/IMG_TargetTraceComponentConfig.png)

3. 在需要追踪目标的地方，调用`TargetTraceSystem`的相关方法。

    ![](Doc/Img/IMG_TargetTraceComponentFunction.png)

    - `Get Target Location`: 获取指定名称的追踪器的追踪结果。
    - `Add or Update Target` and `Remove Target`: 用于临时向追踪系统添加或移除目标，一般用于动态追踪需求。大部分情况下，不需要使用，尽量使用自定义追踪器来实现。

    每当你调用`Get Target Location`时，系统会查找对应追踪器并执行追踪函数，若你需要自定义追踪逻辑，可以在自定义追踪器中实现，方法很简单，首先创建一个`TargetTracer`子类：

    ![](Doc/Img/IMG_CreateCustomTargetTracer.png)

    然后重写`Trace`方法即可，返回的结果即为目标位置：

    ![](Doc/Img/IMG_OverrideTracerFunction.png)

4. 自由拓展系统用法，比如你可以在AnimNotifyState中使用，用于获取玩家当前的位置，并用它制作敌人招式的追踪效果，更多的用法请根据自己需求自行实现，也欢迎大家分享自己的独特用法。

    ![](Doc/Img/IMG_TargetTraceSystemExample.png)

## 关于PR
如果你对该系统有任何改进建议或想法，欢迎提交PR！我们非常欢迎和感谢社区的参与和贡献。
请确保你的PR遵循以下几点：
1. PR应包含清晰的描述，说明你所做的更改和目的。
2. PR应遵循代码风格和规范，以保持代码的一致性和可读性。
3. PR应包含必要的文档更新，以便其他人能够理解你的更改。

## 许可证
本项目采用MIT许可证，详情请查看[LICENSE](LICENSE)文件。