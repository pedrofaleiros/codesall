function imgComp = comprime(img)

  if size(img, 3) == 3
    img = rgb2gray(img);
  endif

  [l c] = size(img);

  imgComp = zeros(floor(l/2), floor(c/2), 'uint8');

  for i = 1:2:l
    for j = 1:2:c
      imgComp(floor(i/2)+1, floor(j/2)+1) = img(i, j);
    endfor
  endfor

