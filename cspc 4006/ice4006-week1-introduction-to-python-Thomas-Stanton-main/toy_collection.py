toy_collection = {
    "Teddy Bear": {
        "age_suitability": 3,
        "is_electronic": False
    },
    "Remote Control Car": {
        "age_suitability": 6,
        "is_electronic": True
    },
}


def add_toy(name, age_suitability, is_electronic):
    collection = {name: {"age_suitability": age_suitability , "is_electronic": is_electronic}}
    toy_collection.update(collection)


def find_toy(name):
    if name in toy_collection:
        return toy_collection[name]
    else:
       return "Toy not found"

def remove_toy(name):
    if name in toy_collection:
        toy_collection.pop(name)
        return "{} removed.".format(name)

def list_toys():
    keys = toy_collection.keys()
    return keys
