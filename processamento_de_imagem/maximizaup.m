function img = maximizaup(x)
    x = double(x) / 255;

    % Pré-alocando a matriz de saída com zeros
    img = zeros(size(x));

    % Encontrando índices do canal com maior valor
    [valor, index] = max(x, [], 3);

    % Canal R
    maskR = (index == 1);
    img(:,:,1) = maskR .* x(:,:,1);

    % Canal G
    maskG = (index == 2);
    img(:,:,2) = maskG .* x(:,:,2);

    % Canal B
    maskB = (index == 3);
    img(:,:,3) = maskB .* x(:,:,3);
end

