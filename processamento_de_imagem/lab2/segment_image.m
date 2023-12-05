function segmented = segment_image(filename, thresholdRatio, minArea)
    % segment_image Segmenta um objeto de uma imagem usando limiarização
    %
    % Argumentos:
    %    filename - Caminho para a imagem que você deseja segmentar
    %    thresholdRatio - Relação do limiar em relação ao valor máximo de pixel em escala de cinza
    %    minArea - Área mínima de objetos para manter após a limiarização
    %
    % Retorno:
    %    segmented - Imagem segmentada com o objeto de interesse e fundo branco

    % Ler a imagem
    img = imread(filename);

    % Converter para escala de cinza
    gray = rgb2gray(img);

    % Limiarização
    thresholdValue = thresholdRatio * max(gray(:));
    binaryMask = gray > thresholdValue;

    % Remover pequenos objetos da máscara binária
    cleanedMask = bwareaopen(binaryMask, minArea);

    % Crie uma imagem de fundo branco do mesmo tamanho da imagem original
    whiteBackground = 255 * ones(size(img), 'uint8');

    % Substitua os pixels do objeto segmentado pelo valor da imagem original
    segmented = bsxfun(@times, whiteBackground, cast(~cleanedMask, 'like', img)) + ...
                bsxfun(@times, img, cast(cleanedMask, 'like', img));

    imshow(segmented);

end

