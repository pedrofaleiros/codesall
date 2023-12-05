function img = resizeImage(inputImage, option)

  inputImage = rgb2gray(inputImage);

  [linhas, colunas] = size(inputImage);

  if option == 1
    img = zeros(2*linhas, 2*colunas);

    for i = 1:linhas
      for j = 1:colunas
        img(2*i-1, 2*j-1) = inputImage(i, j);
        img(2*i, 2*j-1) = inputImage(i, j);
        img(2*i-1, 2*j) = inputImage(i, j);
        img(2*i, 2*j) = inputImage(i, j);
      endfor
    endfor
  endif

  if option == 2
    img = zeros(floor(linhas/2), floor(colunas/2), 'uint8');

    for i = 1:2:linhas
      for j = 1:2:colunas
        img(floor(i/2)+1, floor(j/2)+1) = inputImage(i, j);
      end
    end
  endif
end

