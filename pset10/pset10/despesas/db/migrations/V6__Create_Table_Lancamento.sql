  CREATE  TABLE Lancamentos (
  id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  idUsuario INTEGER NOT NULL,
  data DATETIME NOT NULL,
  idCategoria INTEGER NOT NULL,
  valor REAL NOT NULL,
  Tipo Text NOT NULL,
  idDespesa INTEGER NULL,
  idReceita INTEGER NULL,
  categoria TEXT NOT NULL,
  descricao TEXT NOT NULL,
  dataCriacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  consolidado BOOLEAN DEFAULT FALSE);

-- drop table Lancamento;
