#include "CCmdParser.hpp"

constexpr std::string_view DEFAULT_ALGORITHM = "SP";
constexpr int DEFAULT_START_VERTEX = 0;

void CCmdParser::usage()
{
    std::cout << "Usage: graph_algorithm [-a algorithm] [-s start_vertex] [-f input_file]\n"
              << "\n"
              << "Options:\n"
              << "  -a, --algorithm  Algorithm to run (SP|MST|BFS|DFS). Default: " << DEFAULT_ALGORITHM << "\n"
              << "  -s, --start      Starting vertex for BFS, DFS, and SP algorithms. Default: " << DEFAULT_START_VERTEX << "\n"
              << "  -f, --file       Input file containing graph data. Default: stdin\n";
}

void CCmdParser::parse(int argc, char **argv) 
{
    std::string_view algorithm = DEFAULT_ALGORITHM;
    int start_vertex = DEFAULT_START_VERTEX;
    std::optional<std::string> input_file;

    while (true)
    {
        static struct option long_options[] = {
            {"algorithm", required_argument, 0, 'a'},
            {"start", required_argument, 0, 's'},
            {"file", required_argument, 0, 'f'},
            {0, 0, 0, 0}};

        int option_index = 0;
        int c = getopt_long(argc, argv, "a:s:f:", long_options, &option_index);

        if (c == -1)
        {
            break;
        }

        switch (c)
        {
        case 'a':
            algorithm = optarg;
            break;

        case 's':
            start_vertex = std::stoi(optarg);
            break;

        case 'f':
            input_file = optarg;
            break;

        case 'h':
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

    // Process input file or stdin
    std::ifstream file_stream;
    if (input_file)
    {
        file_stream.open(*input_file);
        if (!file_stream)
        {
            std::cerr << "Failed to open input file: " << *input_file << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // TODO: Process graph data from input file or stdin

    if (file_stream.is_open())
    {
    }
}
