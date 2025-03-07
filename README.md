# 光赛底盘PID控制
## #define 麦轮 全向轮
## 实现功能
* 从其他算法得到期待速度target，自动计算需要输出的pwm，并操作电机实现小车控制
## 潜在问题
* 麦轮建模理论需要验证
* 调参
* 可能存在的逻辑错误或stm32交互上的错误
# 麦轮建模

含有 //@@@ 注释的参数为待测或待实验参数

* 轮子ABCD分别在1234象限
* AB角平分线为x正方向，并且认为此为车“前进”的方向
* BC。。。为y正方向
* 角速度以向上为正方向
* alpha为x正向于AC轮连线夹角 暂时填45
* beta为其余角 暂时填45
* theta为麦轮的辊子和轮子的夹角 暂时填45
* R是单个麦轮到车中心的距离
* 按照4个左旋轮分析，如果是右旋可能要把theta改成135？
* 建模参考https://blog.csdn.net/u014453443/article/details/107228531?sharetype=blog&shareId=107228531&sharerefer=APP&sharesource=2403_88153395&sharefrom=qq

示意图：

B-x-A

y-*--

C---D



# 接线方案
接线参考[mecanum_pid_3.ioc](mecanum_pid_3.ioc)中的引脚名称

# 核心流程
参考[Setup_and_Loop.cpp](Core/Src/Setup_and_Loop.cpp)[robot.cpp](Core/Src/robot.cpp)中robot_control函数的注释

# 进一步开发思路
* 增加位置PID，串级PID增加调控准确度
* 研究能够直接旋转一定角度而不依赖速度的函数
* 
## 下一步上车调参修bug