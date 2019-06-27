# Image Inpainting

windows下面尝试！！
- [ref1](https://www.learnopencv.com/image-inpainting-with-opencv-c-python/)

使用OpenCV进行图像修复（C ++ / Python）
2019年4月2日作者：SATYA MALLICK发表 评论

在今天 岗位 我们将描述一类称为图像修复的区域填充算法。
想象一下找一张旧的家庭照片。你扫描它，它看起来很棒，除了一些划痕。

的 课程你可以在Photoshop中加载照片并修复划痕。但这真的很酷吗？一定不行！

你是一个超级酷的工程师！你有良好的声誉。您打开自己喜欢的编辑器并编写10行代码以使用OpenCV中的修复算法来解决问题。如果你的朋友看起来不那么令人印象深刻，你可以告诉他们这个方法是基于他们在流体动力学中可能遇到的Navier Stokes方程！

但要想那么酷，你需要先阅读这篇文章。

什么是图像修复？
图像修复是计算机视觉中的一类算法，其目标是填充图像或视频内的区域。

使用二元掩模识别该区域，并且通常通过从需要填充的区域的边界传播信息来完成填充。

图像修复的最常见应用是恢复旧的扫描照片。它还用于删除图像中的小的不需要的对象。

修复算法
在本节中，我们将简要讨论在OpenCV中实现的两种修复算法。

### INPAINT_NS： 基于Navier-Stokes的Inpainting
该方法于2001年发表在题为“Navier-Stokes，流体动力学，图像和视频修复”的论文中。

有时我觉得计算机视觉领域是一个来自其他领域的移民领域，如电子工程，计算机科学，物理和数学。

他们将自己的想法带到现场，以非常有趣和独特的方式解决同样的问题。电气工程师可以将图像看作2D信号，并应用信号处理理论来解决计算机视觉问题。另一方面，数学家可以将图像看作连通图并使用图论解决计算机视觉问题。

因此，为流体动力学开发的理论也可以用于计算机视觉，这并不奇怪。


### INPAINT_TELEA：基于快速行进方法
该实施基于Alexandru Telea的题为“ 基于快速行进方法的图像修复技术”的论文。

该实现使用不同的技术解决了相同的约束。作者不使用图像拉普拉斯算子作为平滑度的估计，而是使用像素的已知图像邻域上的加权平均值来补绘。已知的邻域像素和梯度用于估计要修复的像素的颜色。

一旦像素被修复，边界需要更新。作者将图像的缺失区域视为级别集，并使用快速行进方法更新边界。

优点和缺点
根据理论和论文，基于Navier-Stokes的修复应该更慢，并且倾向于产生比基于快速行进的方法更模糊的结果。

在实践中，我们没有发现情况。INPAINT_NS在我们的测试中产生了更好的结果，速度也略高于INPAINT_TELEA。
## Usage

### Python

```
python3 inpaint.py sample.jpeg
```

### C++

```
g++ inpaint.cpp `pkg-config opencv --cflags --libs` -o inpaint
./inpaint sample.jpeg
```
You can also **cmake** as follows:

```
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

The built code can then be used as follows:

```
./build/inpaint sample.jpeg
```

## Performance Comparison

```
Time: FMM = 194445.94073295593 ms
Time: NS = 179731.82344436646 ms
```
