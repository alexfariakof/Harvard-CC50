-- sqlite3 movies.db
-- .schema
-- cat 9.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
    Em 9.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenados por ano de nascimento.
        Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
        Pessoas com o mesmo ano de nascimento podem ser listadas em qualquer ordem.
        Não há necessidade de se preocupar com pessoas que não têm ano de nascimento listado, desde que aquelas que tenham um ano de nascimento estejam listadas em ordem.
        Se uma pessoa apareceu em mais de um filme em 2004, ela deve aparecer apenas uma vez em seus resultados.
*/

Select p.name
  from people p
  inner join stars s on p.id = s.person_id
  inner join movies m on m.id = s.movie_id
  where m.year = 2004 order by p.birth;
