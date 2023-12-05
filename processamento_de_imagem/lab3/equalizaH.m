function [img_eq, H] = equalizaH(img)

  [l, c] = size(img);
  total = l*c;

  n = imhist(img);
  p = n/total;

  s = zeros(1, 256);

  for i = 1: 256
    sum = 0;
    for j = 1: i
      sum += p(j);
    endfor

    sum = sum*256;

    s(i) = round(sum);
  endfor

  img_eq = zeros(l, c, 'uint8');

   for i = 1: l
    for j = 1: c

      valor = img(i, j);
      img_eq(i, j) = s(valor+1);
    endfor
  endfor

  H = imhist(img_eq);



