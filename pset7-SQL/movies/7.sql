
-- sqlite3 movies.db
-- .schema
-- cat 7.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
escreva uma consulta SQL para listar todos os filmes lançados em 2010 e suas classificações,
em ordem decrescente por classificação. Para filmes com a mesma classificação,
ordene-os em ordem alfabética por título.
Sua consulta deve gerar uma tabela com duas colunas, uma para o título de cada filme e outra para a
classificação de cada filme.
Filmes sem classificação não devem ser incluídos no resultado.
*/

Select count(1)
  from movies m
 inner join ratings r on m.id = r.movie_id
 where m.year = 2010

--Select m.title, r.rating From movies m left join ratings r on m.id = r.movie_id  where year = 2010 and r.rating is not null  order by m.title desc;

