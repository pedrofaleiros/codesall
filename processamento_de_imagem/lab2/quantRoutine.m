function Erelat_values = quantRoutine(inputImage)
    Erelat_values = zeros(1, 255);

    for N = 2:256
        [~, Erelat] = quantImage(inputImage, N);
        Erelat_values(N-1) = Erelat;
    end

    % Plot do gráfico
    plot(2:256, Erelat_values);
    title('Erro Relativo em função de N');
    xlabel('N');
    ylabel('Erro Relativo');
    grid on;
end

