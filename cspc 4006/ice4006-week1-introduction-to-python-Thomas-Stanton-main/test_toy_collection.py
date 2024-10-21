from toy_collection import add_toy, find_toy, remove_toy, list_toys

def test_add_toy():
    add_toy("Lego Set", 5, False)
    result = find_toy("Lego Set")
    assert result == {"age_suitability": 5, "is_electronic": False}

def test_find_toy():
    add_toy("Doll", 3, False)
    result = find_toy("Doll")
    assert result == {"age_suitability": 3, "is_electronic": False}

def test_remove_toy():
    add_toy("Toy Car", 4, True)
    result = remove_toy("Toy Car")
    assert result == "Toy Car removed."
    assert find_toy("Toy Car") == "Toy not found"

def test_list_toys():
    add_toy("Ball", 2, False)
    add_toy("Robot", 8, True)
    result = list_toys()
    assert "Ball" in result
    assert "Robot" in result
