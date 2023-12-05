function H = histograma(img)

  H = zeros(1, 256);
  [l, c] = size(img);

  for i = 1: l
    for j = 1: c

      value = img(i, j);
      H(value+1) = H(value+1) + 1;
    endfor
  endfor

