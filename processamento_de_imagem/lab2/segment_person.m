function segmented = segment_person(filename, thresholdRatio, minArea)
    % Ler a imagem
    img = imread(filename);

    % Converter para escala de cinza
    gray = rgb2gray(img);

    % Limiarização
    thresholdValue = thresholdRatio * max(gray(:));
    binaryMask = gray > thresholdValue;

    % Remover pequenos objetos da máscara binária
    cleanedMask = bwareaopen(binaryMask, minArea);

    % Usar operações morfológicas para fechar pequenos buracos
    % No Octave, usaremos um elemento estruturante quadrado
    se = strel('square', 10);
    closedMask = imclose(cleanedMask, se);

    % Criar uma imagem de fundo branco
    whiteBackground = 255 * ones(size(img), 'uint8');

    % Combinar imagem segmentada com fundo branco
    segmented = bsxfun(@times, whiteBackground, cast(~closedMask, 'like', img)) + ...
                bsxfun(@times, img, cast(closedMask, 'like', img));


    imshow(segmented);
end

