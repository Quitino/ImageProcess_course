##  codec
  图像编解码！

- [ref0](https://blog.csdn.net/qq_22207951/article/details/82178803)
- [ref1](http://www.voidcn.com/article/p-ezswooyy-tr.html)
- [ref2](https://www.cnblogs.com/haiyang21/p/9392399.html)
- [ref3](https://cloud.tencent.com/developer/article/1010250)


- cv:: imencode ()函数
bool imencode( const String& ext, InputArray img,
                            CV_OUT std::vector<uchar>& buf,
                       const std::vector<int>& params = std::vector<int>());
功能：实现图像的压缩。
参数：ext：文件拓展名。
img：要被压缩的图像数据。
buf：表示用来存储编码压缩后的图像数据的字符数组。
params：特殊类型文件的写入操作时所需的数据和参数，与imwrite参数相同。



- cv:: imdecode ()函数
Mat imdecode( InputArray buf, int flags, Mat* dst);
功能：实现文件的解码，将字节流数据解码成数组的图像形式。
参数：buf：待解码的字节流。
flags：与imwrite参数相同。
dst：目标图像。


