function reconstruida = fatiamento(imagem, N)

    [l, c] = size(imagem);

    reconstruida = zeros(l, c, 'uint8');

    for k = 1:N
        bitAtual = 9 - k;

        planoAtual = bitget(imagem, bitAtual);

        reconstruida = reconstruida + uint8(planoAtual * 2^(bitAtual - 1));
    end
end

