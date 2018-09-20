function data = importDataTable(path)
[~, ~, glasses] = xlsread(path,'Datatable','A5:A127');
[~, ~, values] = xlsread(path,'Datatable','DM4:EI127');

columnNames = values(1,:);

% Replace invalid symbols
columnNames = replace(columnNames, {'.', ''''}, {'', '1'});

% Get values without column names
values = values(2:end,:);

% Replace non numeric elemenets to NaN
values(cellfun(@(x) ~isnumeric(x), values)) = {NaN};

data = cell2table(values);

data.Properties.VariableNames = columnNames;
data.Properties.RowNames = glasses;
data.Properties.DimensionNames = {'Glasses', 'Values'};
end

