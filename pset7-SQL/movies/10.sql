-- sqlite3 movies.db
-- .schema
-- cat 10.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
   Em 10.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0.
    Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
    Se uma pessoa dirigiu mais de um filme que recebeu uma classificação de pelo menos 9,0, ela deve aparecer apenas uma vez em seus resultados.
*/

Select p.name
  from people p
 inner join directors d on p.id = d.person_id
 inner join ratings r on r.movie_id = d.movie_id
 where rating >= 9.0;