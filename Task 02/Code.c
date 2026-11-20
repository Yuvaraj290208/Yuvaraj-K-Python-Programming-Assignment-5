import sys
from decimal import Decimal[span_6](start_span)[span_6](end_span)

# 1. Interactive type and operator checks[span_7](start_span)[span_7](end_span)
print("Types:", type(10), type(10.0), type("10"), type(True), type((10, 8.5)))[span_8](start_span)[span_8](end_span)
print("Division:", 7 / 2, 7 // 2, 7 % 2, -7 // 2)[span_9](start_span)[span_9](end_span)
print("Float equality 0.1 + 0.2 == 0.3:", 0.1 + 0.2 == 0.3)[span_10](start_span)[span_10](end_span)

# 2. Complete the Code (TODO 1)[span_11](start_span)[span_11](end_span)[span_12](start_span)[span_12](end_span)
payments = ["33.40"] * 1000 + ["0.10"] * 3[span_13](start_span)[span_13](end_span)

def total_float(items):[span_14](start_span)[span_14](end_span)
    total = 0.0[span_15](start_span)[span_15](end_span)
    for amount in items:[span_16](start_span)[span_16](end_span)
        total += float(amount)[span_17](start_span)[span_17](end_span)
    return total[span_18](start_span)[span_18](end_span)

def total_decimal(items):[span_19](start_span)[span_19](end_span)
    # TODO 1: Add the amounts exactLy by creating a Decimal from each string, and return the Decimal total[span_20](start_span)[span_20](end_span)
    total = Decimal("0.00")
    for amount in items:
        total += Decimal(amount)
    return total

print("float :", total_float(payments))[span_21](start_span)[span_21](end_span)
print("Decimal:", total_decimal(payments))[span_22](start_span)[span_22](end_span)
print(0.1 + 0.2 == 0.3, Decimal("0.1") + Decimal("0.2") == Decimal("0.3"))[span_23](start_span)[span_23](end_span)

# 3. Variant using Decimal(float(amount)) and Alternative Paise (int)[span_24](start_span)[span_24](end_span)
def total_decimal_from_float(items):
    total = Decimal("0")
    for amount in items:
        total += Decimal(float(amount))  # Inherits binary float imprecision[span_25](start_span)[span_25](end_span)
    return total

def total_paise(items):
    total = 0
    for amount in items:
        # Convert rupees string to integer paise cleanly
        total += int(round(float(amount) * 100))
    return total / 100

print("Decimal(float):", total_decimal_from_float(payments))[span_26](start_span)[span_26](end_span)
print("Paise (int)   :", total_paise(payments))[span_27](start_span)[span_27](end_span)
print("Memory (bytes) -> int paise:", sys.getsizeof(3340030), "Decimal:", sys.getsizeof(Decimal("33400.30")))[span_28](start_span)[span_28](end_span)
