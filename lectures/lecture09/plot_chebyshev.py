def PlotChebyshev():
    import matplotlib.pyplot as plt

    x_vals = []
    y_vals = []

    with open("chebyshev_data.data", "r") as file:
        for line in file:
            x, y = map(float, line.split())
            x_vals.append(x)
            y_vals.append(y)

    plt.plot(x_vals, y_vals, label="pN(x)")
    plt.title("Chebyshev Polynomial Sum")
    plt.xlabel("x")
    plt.ylabel("pN(x)")
    plt.grid(True)
    plt.legend()
    plt.savefig('chebyshev_plot.png', dpi = 400, bbox_inches ='tight')
    plt.show()


if __name__ == "__main__":
    PlotChebyshev()
