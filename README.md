# ros-opencv
ros-opencv

## 题目是老师给的一点点学习目标

>使用ros节点 实现对红色蓝色、黄色物体的跟踪。 红色物体比如是瓶盖。有动态参数可以配置，进行一些参数设定。
>基础要求是对一定大小的单目标进行跟踪，进阶是对多目标跟踪。
>要求代码符合googlecpp规范。
>
>分以下节点：
>1 生产者：读取图像，发布图像
>2 消费者：订阅图像 opencv处理 目标识别和跟踪 输出结果
>3 可视化： 订阅生产者和消费者的数据，输出识别结果进行可视化。
>4 将节点23功能合并。
>
>注意最后演示分两种，一种是节点 123 一种是节点。

## 目前进度：

- 2022-6-5 

目前master进度是完成对四种颜色物体的识别，分支single-track是尝试学习使用opencv集成的跟踪算法，目前还在做。

- [x] 完成对四种颜色物体的识别
- [x] 完成节点123
- [ ] 符合googlecpp规范
- [ ] 跟踪？maybe
- [ ] 合并节点23
