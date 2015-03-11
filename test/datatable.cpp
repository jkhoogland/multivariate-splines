#include "catch.hpp"
#include "testingutilities.h"
#include "datatable.h"
#include "serialize.h"

using namespace MultivariateSplines;


TEST_CASE("DataTable save and load case 1", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(1);
    double y;
    for (double i = -0.3; i <= 0.3; i += 0.04)
    {
        x.at(0) = i;
        y = 2 * i;
        table.addSample(x, y);
    }

    table.save("test1.datatable");

    DataTable loadedTable("test1.datatable");

    remove("test1.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}


TEST_CASE("DataTable save and load case 2", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(2);
    double y;
    for (double i = -0.3; i <= 0.3; i += 0.04)
    {
        for (double j = -0.4; j <= 1.0; j += 0.08)
        {
            x.at(0) = i;
            x.at(1) = j;
            y = i * j;
            table.addSample(x, y);
        }
    }

    table.save("test2.datatable");

    DataTable loadedTable("test2.datatable");

    remove("test2.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}


TEST_CASE("DataTable save and load case 3", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(2);
    double y;
    for (double i = -0.3; i <= 0.3; i += 0.04)
    {
        for (double j = -0.4; j <= 1.0; j += 0.03)
        {
            x.at(0) = i;
            x.at(1) = j;
            y = i * j;
            table.addSample(x, y);
        }
    }

    table.save("test3.datatable");

    DataTable loadedTable("test3.datatable");

    remove("test3.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}

TEST_CASE("DataTable save and load case 4", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(4);
    double y;
    int j = 0;
    for (double i = std::numeric_limits<double>::lowest(), k = std::numeric_limits<double>::max();
         j < 10000;
         i = nextafter(i, std::numeric_limits<double>::max()), k = nextafter(k, std::numeric_limits<double>::lowest()))
    {
        x.at(0) = i;
        y = k;
        table.addSample(x, y);
        j++;
    }

    table.save("test4.datatable");

    DataTable loadedTable("test4.datatable");

    remove("test4.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}


TEST_CASE("DataTable save and load case 5", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(3);
    double y;
    for (double i = -0.0001; i <= 0.0001; i += 0.000001)
    {
        for (double j = -0.01; j <= 0.01; j += 0.001)
        {
            for (double k = -0.01; k <= 0.01; k += 0.001)
            {
                x.at(0) = i;
                x.at(1) = j;
                x.at(2) = k;
                y = i * j;
                table.addSample(x, y);
            }
        }
    }

    table.save("test5.datatable");

    DataTable loadedTable("test5.datatable");

    remove("test5.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}


TEST_CASE("DataTable save and load case 6", "[saveload]") {
    DataTable table;

    auto x = std::vector<double>(4);
    double y;
    for (double i = -0.0001; i <= 0.0001; i += 0.000001)
    {
        for (double j = -0.01; j <= 0.01; j += 0.001)
        {
            for (double k = -0.01; k <= 0.01; k += 0.001)
            {
                for (double l = -100000.0; l < -60000.0; l += 13720.0)
                {
                    x.at(0) = i;
                    x.at(1) = j;
                    x.at(2) = k;
                    x.at(3) = l;
                    y = i * j;
                    table.addSample(x, y);
                }
            }
        }
    }

    table.save("test6.datatable");

    DataTable loadedTable("test6.datatable");

    remove("test6.datatable");

    REQUIRE(compareDataTables(table, loadedTable));
}
