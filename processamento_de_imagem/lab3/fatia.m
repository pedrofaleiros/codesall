function response = fatia(img, N)

  [l c] = size(img);

  response = zeros(l, c, 'uint8');

  for i = 1: N
    bitvalue = (2^(8-i));
    response = response + bitvalue * bitget(img, 9-i);
  end
end
