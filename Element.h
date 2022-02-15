#pragma once

#include <map>
#include <vector>

enum class Element
{
    Water,
    Grass,
    Fire
};

static const std::map<Element, std::vector<Element>> Weaknesses = {
    {Element::Water, {Element::Grass}},
    {Element::Grass, {Element::Fire}},
    {Element::Fire, {Element::Water}}
};

static const std::map<Element, std::vector<Element>> Strengths = {
    {Element::Water, {Element::Fire}},
    {Element::Grass, {Element::Water}},
    {Element::Fire, {Element::Grass}}
};

