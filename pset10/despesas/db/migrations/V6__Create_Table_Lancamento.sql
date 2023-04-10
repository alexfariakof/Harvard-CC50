CREATE  TABLE Lancamento (
  id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  idUsuario INTEGER NULL,
  idDespesa INTEGER NULL,
  idReceita INTEGER NULL,
  valor REAL NULL,
  data TEXT NULL,
  descricao TEXT NULL,
  dataCriacao TEXT);