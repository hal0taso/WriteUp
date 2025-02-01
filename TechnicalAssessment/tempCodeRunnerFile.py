import gurobipy

def combination_exists(objects: list[int], target: int) -> bool:
    """
    Check if there is a combination of the
    given objects that sum up to the target value.

    Args:
    objects: list of integers, the values of the objects
    target: integer, the target value

    Returns:
    bool: True if there is a combination of the given objects
          that sum up to the target value, False otherwise
    """
    # Create a new model
    model = gurobipy.Model("combination_exists")
    # disable output
    model.setParam('OutputFlag', 0)

    # Create variables
    # x[i]: 1 if the i-th object is selected, 0 otherwise
    x = model.addVars(
        len(objects),
        vtype=gurobipy.GRB.BINARY,
        name="x"
    )

    # Set objective (just only check the feasibility)
    model.setObjective(0, gurobipy.GRB.MAXIMIZE)

    # Add constraint
    model.addConstr(
        gurobipy.quicksum(
            x[i] * objects[i] for i in range(len(objects))
        ) == target
    )

    # Optimize model
    model.optimize()

    # Return true if the model is feasible
    return model.status == gurobipy.GRB.OPTIMAL


def test_verification():
    # from example
    assert combination_exists([1, 5, 3, 6], 7)
    assert not combination_exists([1, 5, 3, 6], 13)
    # from example
    assert combination_exists([2, 1, 5, 3, 2], 6)
    # hand-maded example
    # always true if target is 0
    assert combination_exists([1, 2, 3], 0)
    assert combination_exists([1, 2, 3], 1)
    assert combination_exists([1, 2, 3], 2)
    assert combination_exists([1, 2, 3], 3)
    assert combination_exists([1, 2, 3], 4)
    assert combination_exists([1, 2, 3], 5)
    assert combination_exists([1, 2, 3], 6)
    assert not combination_exists([1, 2, 3], 7)
    assert combination_exists([2,1,5,3,2],4)
    assert combination_exists([2,1,5,3,2],4)
    assert not combination_exists([2,1,5],4)

if __name__ == "__main__":
    test_verification()
    print("All tests passed")