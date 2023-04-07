-- $ cat filename.sql | sqlite3 movies.db
-- $ cat filename.sql | sqlite3 movies.db > output.txt
-- check50 cs50/problems/2021/x/movies

-- Em 1.sql, escreva uma consulta SQL para listar os títulos de todos os filmes lançados em 2008.
-- Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
-- A execução de 1.sql resulta em uma tabela com 1 coluna e 9.545 linhas.

Select title From movies where year = 2008;
