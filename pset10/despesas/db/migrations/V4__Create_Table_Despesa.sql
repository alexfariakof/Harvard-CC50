CREATE  TABLE Despesa (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  idUsuario INTEGER,
  idCategoria INTEGER,
  data TEXT NULL,
  descricao TEXT,
  valor real NULL ,
  dataVencimento TEXT);