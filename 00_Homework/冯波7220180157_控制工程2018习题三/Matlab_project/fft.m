close all
f_1 = imread('图片1.jpg');
figure();
subplot(2,3,1),imshow(f_1),title('原图一');
f = im2double(f_1)
%f1 = rgb2gray(
fft_f1 = fft2(f);
fft_s = abs(fft_f1);
subplot(2,3,2),imshow(im2uint8(mat2gray(log(1+fft_s)))),title('原图一傅里叶');
fc = fftshift(fft_f1);
fc_s = abs(fc);
subplot(2,3,3),imshow(im2uint8(mat2gray(log(1+fc_s)))),title('原图一傅里叶中心化');

f_2 = imread('图片2.jpg');
subplot(2,3,4),imshow(f_2),title('原图一');
f2 = im2double(f_2)
%f1 = rgb2gray(
fft_f2 = fft2(f2);
fft_s2 = abs(fft_f2);
subplot(2,3,5),imshow(im2uint8(mat2gray(log(1+fft_s2)))),title('原图一傅里叶');
fc2 = fftshift(fft_f2);
fc_s2 = abs(fc2);
subplot(2,3,6),imshow(im2uint8(mat2gray(log(1+fc_s2)))),title('原图一傅里叶中心化');