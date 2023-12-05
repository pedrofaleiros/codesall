function g = serie_Fourier_onda_quadrada(N)

  t = 0:0.1:10*pi;
  g = zeros(1, length(t));

  for n=0:N
    g = g + (4/((2*n+1)*pi))*sin((2*n+1)*t);
  endfor

  plot(t, g, 'k');

