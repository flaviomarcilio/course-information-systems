#include <iostream>

#include "../include/item.h"

/**
 * @brief Constrói um novo item
 * 
 * @param url URL
 * @param views Quantidade de visualizações
 * @param fita Número do arquivo onde será gravado
 */
Item::Item(string url, int views, int fita)
{
    url_ = url;
    views_ = views;
    fita_ = fita;
}

/**
 * @brief Faz a comparação entre dois itens
 * 
 * @param item 
 * @return int 
 */
int Item::compara(const Item *item)
{
    if (views_ < item->views_) return -1;
    else if (views_ > item->views_) return 1;
    return item->url_.compare(url_);
}

/**
 * @brief Converte o item para uma string
 * 
 * @return string 
 */
string Item::toString()
{
    return url_ + " " + std::to_string(views_);
}