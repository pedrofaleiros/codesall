function showmax(name)
  x = imread(strcat('images/', name));

  [l c ~] = size(x);

  if l > 2000
    x = imresize(x, 0.25);
  endif

  [l c ~] = size(x);
  l
  c

  y = maximizaup(x);
  x = double(x)/255;

  imshow([x y]);
