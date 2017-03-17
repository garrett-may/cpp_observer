#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

namespace observer
{

template <typename T>
void addEventHandler(void (*handler)(T));

template <typename T>
bool removeEventHandler(void (*handler)(T));

template <typename T>
void fire(T& t);

}

template <typename T>
using Handler = void (*)(T);

template <typename T>
std::unordered_map<std::type_index, std::vector<Handler<T>>> map;

namespace observer
{

template <typename T>
void addEventHandler(Handler<T> handler)
{
	auto handlers = (map<T>.count(typeid(T)))
					? map<T>[typeid(T)]
					: std::vector<Handler<T>>();
	handlers.push_back(handler);
	map<T>[typeid(T)] = handlers;
}

template <typename T>
bool removeEventHandler(Handler<T> handler)
{
	auto handlers = (map<T>.count(typeid(T)))
					? map<T>[typeid(T)]
					: std::vector<Handler<T>>();
	auto isRemoved = false;
	for(unsigned int i = 0; i < handlers.size(); i++)
	{
		if(handlers[i] == handler)
		{
			handlers.erase(handlers.begin() + i);
			isRemoved = true;
		}
	}
	map<T>[typeid(T)] = handlers;
	return isRemoved;
}

template <typename T>
void fire(T& t)
{
	auto handlers = (map<T>.count(typeid(T)))
					? map<T>[typeid(T)]
					: std::vector<Handler<T>>();
	for(auto handler : handlers)
	{
		handler(t);
	}
}

}