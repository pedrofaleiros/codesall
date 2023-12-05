function res = teste(img, img_g, x)

  [l c ~] = size(img);

  for i = 1:l
     for j = 1:c
       res(i, j, 1) = img(i, j, 1)  ;
       res(i, j, 2) = img(i, j, 2)  ;
       res(i, j, 3) = img(i, j, 3)  ;
     endfor
   endfor

