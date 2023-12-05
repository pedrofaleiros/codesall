function [imgQuant, Erelat] = quantImage(img, N)

    img = rgb2gray(img);
    img = double(img)/255;

    passo = 1/(N-1);
    escala = 0:passo:1;

    imgQuant = zeros(size(img));
    [l, c] = size(img);

    for i = 1:l
      for j = 1:c
        dif = abs(escala - img(i, j));
        [~, index] = min(dif);
        imgQuant(i, j) = escala(index);
      endfor
    endfor

    cima = 0;
    baixo = 0;
    for i = 1:l
      for j = 1:c
        cima = cima + (abs(img(i, j) - imgQuant(i, j)))^2;
        baixo = baixo + (abs(img(i, j)))^2;
      endfor
    endfor

    Erelat = cima/baixo;
end

