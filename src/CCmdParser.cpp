#include "CCmdParser.hpp"

constexpr std::string_view DEFAULT_ALGORITHM = "SP";
constexpr std::string_view DEFAULT_REPRESENTATION = "AL";
constexpr int DEFAULT_START_VERTEX = 0;

params::params(std::string_view algorithm, std::string_view representation, std::optional<int> startVertex, std::optional<std::string> filePath,
               std::optional<double> density, std::optional<int> verticesCount) : m_algorithm(algorithm), m_representation(representation), m_startVertex(startVertex),
                                                                                  m_filePath(filePath), m_density(density), m_verticesCount(verticesCount)
{
}

void CCmdParser::usage()
{
    std::cout << "Usage: graph_algorithm [-a algorithm] [-s start_vertex] [-f input_file]\n"
              << "Usage: graph_algorithm [-a algorithm] [-s start_vertex] [-d density] [-v vertices-count]\n"
              << "\n"
              << "Options:\n"
              << "  -a, --algorithm       Algorithm to run (SP|MST|BFS|DFS). Default: " << DEFAULT_ALGORITHM << "\n"
              << "  -r, --representation  GraphRepresentation (AL|AM). Default: " << DEFAULT_REPRESENTATION << "\n"
              << "  -s, --start           Starting vertex for BFS, DFS, and SP algorithms. Default: " << DEFAULT_START_VERTEX << "\n"
              << "  -f, --file            Input file containing graph data. Default: stdin\n"
              << "  -d, --density         Generated graph density: stdin\n"
              << "  -v, --vertices-count   Generated graph vertices count. Default: stdin\n";
}

params CCmdParser::parse(int argc, char **argv)
{
    std::string_view algorithm = DEFAULT_ALGORITHM;
    std::string_view representation;
    int start_vertex = DEFAULT_START_VERTEX;
    std::optional<std::string> input_file;
    std::optional<double> density;
    std::optional<int> vertices_count;

    while (true)
    {
        static struct option long_options[] = {
            {"algorithm", required_argument, 0, 'a'},
            {"representation", required_argument, 0, 'r'},
            {"start", required_argument, 0, 's'},
            {"file", required_argument, 0, 'f'},
            {"density", required_argument, 0, 'd'},
            {"verticesCount", required_argument, 0, 'v'},
            {0, 0, 0, 0}};

        int option_index = 0;
        int c = getopt_long(argc, argv, "a:r:s:f:d:v", long_options, &option_index);

        if (c == -1)
        {
            break;
        }

        switch (c)
        {
        case 'a':
            algorithm = optarg;
            break;
        case 'r':
            representation = optarg;
            break;
        case 's':
            start_vertex = std::stoi(optarg);
            break;
        case 'f':
            input_file = optarg;
            break;
        case 'd':
            density = std::stod(optarg);
            break;
        case 'v':
            vertices_count = std::stoi(optarg);
            break;
        case '?':
            usage();
            exit(EXIT_FAILURE);
        }
    }

    if (optind < argc)
    {
        std::cout << "Non-option arguments:";
        while (optind < argc)
        {
            std::cout << " " << argv[optind++];
        }
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    // Run the selected algorithm on the input graph
    if (algorithm == "SP")
    {
        std::cout << "Running Shortest Path algorithm with start vertex " << start_vertex << std::endl;
    }
    else if (algorithm == "MST")
    {

        std::cout << "Running Minimal Spanning Tree algorithm\n";
    }
    else if (algorithm == "BFS")
    {
        std::cout << "Running Breadth First Search algorithm with start vertex " << start_vertex << std::endl;
    }
    else if (algorithm == "DFS")
    {
        std::cout << "Running Depth First Search algorithm with start vertex " << start_vertex << std::endl;
    }
    else
    {
        std::cout << "Unknown algorithm: " << algorithm << std::endl;
        exit(EXIT_FAILURE);
    }

    if (input_file)
    {
        if (!fs::exists(*input_file))
        {
            std::cerr << "File: " << *input_file << " does not exist" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (!density || !vertices_count)
    {
        std::cerr << "vertices count or density for graph generation not specified " << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (density.value() < 0 || density.value() > 1)
    {
        std::cerr << "Graph density have to be in scope of <0-1>" << std::endl;
        exit(EXIT_FAILURE);
    }

    return params(algorithm, representation, start_vertex, input_file, density, vertices_count);
}
