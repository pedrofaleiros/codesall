function Erelat_values = erelatPlot(img)
    erelatValues = zeros(1, 255);

    for N = 2:256
      N
      [~, erelat] = quantImage(img, N);
      erelatValues(N-1) = erelat;
    endfor

    plot(2:256, erelatValues);
    xlabel('N');
    ylabel('Erro Relativo');

end

