rm(list = ls())

overflow_divisao_inser = c(0.039059, 0.038415, 0.039378, 0.039011, 0.041119, 0.045906, 0.039444, 0.039126, 0.042049, 0.038666)
overflow_divisao_busca = c(9.117072, 9.107867, 9.063285, 9.114259, 9.419514, 9.140769, 9.120253, 9.122361, 9.366557, 9.123404)
overflow_divisao_coli = 3172570

overflow_mult_inser = c(0.232226, 0.232506, 0.239973, 0.230474, 0.231548, 0.242643, 0.229353, 0.227546, 0.245360, 0.234330)
overflow_mult_busca = c(39.006634, 39.546329, 38.884270, 39.175756, 39.633743, 38.913583, 38.912782, 40.211987, 42.226321, 38.93973)
overflow_mult_coli = 4911294

hash_duplo_inser = c(0.136085, 0.139056, 0.140267, 0.135824, 0.134695, 0.135971, 0.141437, 0.137631, 0.132644, 0.133711)
hash_duplo_busca = c(70.332442, 70.313453, 70.733132, 70.811036, 70.085041, 73.480530, 71.310348, 70.437991, 71.102842, 70.37701)
hash_duplo_coli = 1547514

aberto_divisao_inser = c(0.008537, 0.008139, 0.008417, 0.008466, 0.007731, 0.008475, 0.009659, 0.008549, 0.008558, 0.009136)
aberto_divisao_busca = c(0.007775, 0.008425, 0.008582, 0.008903, 0.007423, 0.007057, 0.007461, 0.007746, 0.007262, 0.007174)
aberto_divisao_coli = 39582

aberto_mult_inser = c(0.011289, 0.012902, 0.011868, 0.011262, 0.010892, 0.010865, 0.011618, 0.011051, 0.011232, 0.011072)
aberto_mult_busca = c(0.049784, 0.055107, 0.046157, 0.049617, 0.048671, 0.048211, 0.048347, 0.050129, 0.055702, 0.053838)
aberto_mult_coli = 49495

metodos = c("Progressivo: divisão", "Progressivo: multiplicação", "Hash duplo", "Aberto: divisão", "Aberto: multiplicação")
colisoes = c(overflow_divisao_coli, overflow_mult_coli, hash_duplo_coli, aberto_divisao_coli, aberto_mult_coli)
medias_inser = c(mean(overflow_divisao_inser), mean(overflow_mult_inser), mean(hash_duplo_inser), mean(aberto_divisao_inser), mean(aberto_mult_inser))
dp_inser = c(sd(overflow_divisao_inser), sd(overflow_mult_inser), sd(hash_duplo_inser), sd(aberto_divisao_inser), sd(aberto_mult_inser))

medias_busca = c(mean(overflow_divisao_busca), mean(overflow_mult_busca), mean(hash_duplo_busca), mean(aberto_divisao_busca), mean(aberto_mult_busca))
dp_busca = c(sd(overflow_divisao_busca), sd(overflow_mult_busca), sd(hash_duplo_busca), sd(aberto_divisao_busca), sd(aberto_mult_busca))


barplot(colisoes, names.arg = metodos, main = "Colisões", xlab = "Métodos", ylab = "Quantidade de colisões")

bar_inser = barplot(medias_inser, main = "Tempos de inserção", names.arg = metodos, xlab = "Métodos", ylab = "Média", ylim = c(0, 0.25))
arrows(bar_inser, medias_inser+dp_inser, bar_inser, medias_inser-dp_inser, length = 0.1, angle = 90, code = 3)

bar_busca = barplot(medias_busca, main = "Tempos de busca", names.arg = metodos, xlab = "Métodos", ylab = "Média", ylim = c(0, 75))
arrows(bar_busca, medias_busca+dp_busca, bar_busca, medias_busca-dp_busca, length = 0.1, angle = 90, code = 3)
