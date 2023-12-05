function imgDil = dilata(img)

  if size(img, 3) == 3
    img = rgb2gray(img);
  endif

  [l c] = size(img);

  imgDil = zeros(2*l, 2*c, 'uint8');

  for i = 1:l
    for j = 1:c
      imgDil(2*i-1, 2*j-1) = img(i, j);
      imgDil(2*i  , 2*j-1) = img(i, j);
      imgDil(2*i-1, 2*j) = img(i, j);
      imgDil(2*i  , 2*j) = img(i, j);
    endfor
  endfor

