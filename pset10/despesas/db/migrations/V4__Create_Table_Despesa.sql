CREATE  TABLE Despesa (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  idUsuario INTEGER NOT NULL,
  idCategoria INTEGER NOT NULL,
  data DATETIME DEFAULT CURRENT_DATE,
  descricao TEXT,
  valor REAL NULL ,
  dataVencimento DATETIME NULL);


  Select d.id, d.idUsuario, c.descricao as categoria, tc.descricao as Tipo, d.data, d.descricao, d.valor 
    From Despesa d
     Inner Join Categoria c on d.idCategoria = c.id
     Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id;


Select strftime('%d/%m/%Y %H:%M:%S', data) as data from Despesa;