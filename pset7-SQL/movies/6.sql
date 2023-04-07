-- sqlite3 movies.db
-- .schema
-- cat 6.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies

/*
/* escreva uma consulta SQL para determinar a avaliação média de todos os filmes lançados em 2012.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho)
contendo a classificação média. */

Select AVG(rating) from ratings where  movie_id in  (Select id as soma from  movies m  where m.year= 2012 group by title);



