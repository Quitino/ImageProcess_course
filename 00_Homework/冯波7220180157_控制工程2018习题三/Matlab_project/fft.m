close all
f_1 = imread('ͼƬ1.jpg');
figure();
subplot(2,3,1),imshow(f_1),title('ԭͼһ');
f = im2double(f_1)
%f1 = rgb2gray(
fft_f1 = fft2(f);
fft_s = abs(fft_f1);
subplot(2,3,2),imshow(im2uint8(mat2gray(log(1+fft_s)))),title('ԭͼһ����Ҷ');
fc = fftshift(fft_f1);
fc_s = abs(fc);
subplot(2,3,3),imshow(im2uint8(mat2gray(log(1+fc_s)))),title('ԭͼһ����Ҷ���Ļ�');

f_2 = imread('ͼƬ2.jpg');
subplot(2,3,4),imshow(f_2),title('ԭͼһ');
f2 = im2double(f_2)
%f1 = rgb2gray(
fft_f2 = fft2(f2);
fft_s2 = abs(fft_f2);
subplot(2,3,5),imshow(im2uint8(mat2gray(log(1+fft_s2)))),title('ԭͼһ����Ҷ');
fc2 = fftshift(fft_f2);
fc_s2 = abs(fc2);
subplot(2,3,6),imshow(im2uint8(mat2gray(log(1+fc_s2)))),title('ԭͼһ����Ҷ���Ļ�');