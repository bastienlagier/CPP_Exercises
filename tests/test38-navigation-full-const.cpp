#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Extracting data from pokedex.json, ensuring that it works on const NodePtr. ")
{
    /*
        This tests require to "duplicate" a lot of functions already written.
        Check that test 35 passes afterwards.
    */

    std::unique_ptr<const Node> node = JsonParser::parse_from_file(json_dir + "pokedex.json");
    /*\             ^^^^^   Note this const                                                 \*/

    REQUIRE(node->kind() == NodeKind::OBJECT);
    REQUIRE(node->as_ObjectNode()->has_child("pokemon"));
    REQUIRE(node->as_ObjectNode()->at("pokemon")->kind() == NodeKind::ARRAY);

    /* This map associates each pokemon name to its pokedex number */
    std::unordered_map<std::string, unsigned> pokemon_name_to_id;
    const ArrayNode &pokemons_node = *(node->as_ObjectNode()->at("pokemon")->as_ArrayNode());
    for (const auto &pokemon_node : pokemons_node)
    {
        REQUIRE(pokemon_node->kind() == NodeKind::OBJECT);
        auto pokemon_obj = pokemon_node->as_ObjectNode();

        REQUIRE(pokemon_obj->has_child("name"));
        
        REQUIRE(pokemon_obj->at("name")->kind() == NodeKind::STRING);
        const std::string &name = pokemon_obj->at("name")->as_StringLeaf()->data();

        REQUIRE(pokemon_obj->has_child("id"));
        REQUIRE(pokemon_obj->at("id")->kind() == NodeKind::INT);
        unsigned id = pokemon_obj->at("id")->as_IntLeaf()->data();

        pokemon_name_to_id[name] = id;
    }

    REQUIRE(pokemon_name_to_id["Bulbasaur"] == 1);
    REQUIRE(pokemon_name_to_id["Pikachu"] == 25);
    REQUIRE(pokemon_name_to_id["Mewtwo"] == 150);
}

#include "routine_memory_check.cpp"