function snr_db = testa()
  x = [0.1:0.1:1];
  x = x/1000;

  for i = 1:10
    snr_db(i) = TesteAudio(x(i));
  endfor

