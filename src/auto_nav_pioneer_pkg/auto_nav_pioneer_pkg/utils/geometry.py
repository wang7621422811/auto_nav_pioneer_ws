"""Geometry helpers: angle wrapping, quaternion to yaw, etc."""

from math import atan2, pi, sqrt

"""
我用**最简单、最通俗、不带任何专业架子**的话给你讲，保证你马上懂！

# 1. 这个函数是干嘛的？
一句话：
**把任何一个角度，强行掰到 -π 到 +π 之间（-180° ~ 180°）**

就像钟表指针转多了，我给你掰回正常范围。

---

# 2. 逐行翻译成人话
```python
def wrap_angle(angle_rad: float) -> float:
```
我定义一个叫 **wrap_angle** 的函数，
**输入**：一个角度（弧度）
**输出**：一个处理好的角度（弧度）

```python
Wrap an angle to the range [-pi, +pi].
```
注释：把角度限制在 **-π 到 π** 之间

```python
while angle_rad > pi:
    angle_rad -= 2 * pi
```
如果角度 **太大了（比 π 还大）**
就 **减一圈（2π）**
一直减到它 ≤ π

比如：4π → 减2π → 2π → 再减2π → 0

```python
while angle_rad < -pi:
    angle_rad += 2 * pi
```
如果角度 **太小了（比 -π 还小）**
就 **加一圈（2π）**
一直加到它 ≥ -π

比如：-3π → 加2π → -π

```python
return angle_rad
```
返回处理好的正常角度

---

# 3. 举个超级简单的例子（一看就懂）
π = 180°
2π = 360°

### 例子1：输入 270°（= 1.5π）
比 π 大
→ 减 2π
→ 1.5π - 2π = **-0.5π（-90°）**

### 例子2：输入 -270°（= -1.5π）
比 -π 小
→ 加 2π
→ -1.5π + 2π = **0.5π（90°）**

### 例子3：输入 90°（0.5π）
本来就在范围内 → **直接返回 0.5π**

---

# 4. 为什么机器人要用这个？
因为机器人转向时，角度会一直转、一直累加：
360°、720°、1080°……
但机器人**只关心 -180° ~ 180°** 这个范围。

这个函数就是**把转了好多圈的角度，变回一圈内的正常角度**。

---

# 5. 超级总结（你只需要记这句）
**不管你给我多大、多小的角度，我都给你掰回 -180° ~ 180° 之间。**

---
如果你愿意，我可以再给你画个图、或者用更简单的代码重写一遍！

"""


def wrap_angle(angle_rad: float) -> float:
    """Wrap an angle to the range [-pi, +pi]."""
    while angle_rad > pi:
        angle_rad -= 2 * pi
    while angle_rad < -pi:
        angle_rad += 2 * pi
    return angle_rad


def quaternion_to_yaw(qx: float, qy: float, qz: float, qw: float) -> float:
    """Extract yaw (rotation around Z axis) from a quaternion.

    Returns yaw in radians, range [-pi, +pi].
    This is the robot's heading in the XY plane.
    """
    # Simplified formula for yaw-only (roll=0, pitch=0 assumed flat ground)
    siny_cosp = 2.0 * (qw * qz + qx * qy)
    cosy_cosp = 1.0 - 2.0 * (qy * qy + qz * qz)
    return atan2(siny_cosp, cosy_cosp)


def distance_2d(x1: float, y1: float, x2: float, y2: float) -> float:
    """Euclidean distance between two 2D points."""
    return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)