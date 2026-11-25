#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
#include <stdexcept>

struct edge {
	int first, second, weight;
};

typedef std::vector< std::vector< std::pair<int,int> > > adj_list;

std::vector<edge> kruskal(const adj_list& graph);
int get_pred(int vertex, const std::vector<int>& pred);
void run_pipeline_optimization();

int main() {
	try {
		run_pipeline_optimization();
	} catch (const std::invalid_argument& e) {
		std::cerr << "\n[KESALAHAN INPUT / ARGUMEN]: " << e.what() << "\n";
		return 1;
	} catch (const std::out_of_range& e) {
		std::cerr << "\n[KESALAHAN BATAS INDEKS]: " << e.what() << "\n";
		return 1;
	} catch (const std::runtime_error& e) {
		std::cerr << "\n[KESALAHAN SISTEM / LOGIKA JARINGAN]: " << e.what() << "\n";
		return 1;
	} catch (const std::exception& e) {
		std::cerr << "\n[TERJADI EKSEPSI TAK TERDUGA]: " << e.what() << "\n";
		return 1;
	} catch (...) {
		std::cerr << "\n[ERROR]: Terjadi kesalahan kritis tak dikenal.\n";
		return 1;
	}

	return 0;
}

void run_pipeline_optimization() {
	const int n = 5;
	int m = 0;

	std::cout << "=================================================================\n";
	std::cout << "  SISTEM OPTIMASI JARINGAN PIPA INDUK AIR BERSIH PERUMAHAN\n";
	std::cout << "  Titik Distribusi Utama: A, B, C, D, E (5 Titik)\n";
	std::cout << "=================================================================\n\n";

	std::cout << "Masukkan jumlah kandidat jalur pipa yang dapat dibangun (m): ";
	std::string input_line;
	
	while (std::getline(std::cin, input_line)) {
		if (input_line.find_first_not_of(" \t\r\n") != std::string::npos) break;
	}

	if (input_line.empty() || input_line.find_first_not_of(" \t\r\n") == std::string::npos) {
		throw std::runtime_error("Input kosong atau mencapai EOF sebelum jumlah jalur (m) terbaca.");
	}

	std::istringstream ss(input_line);
	int val1, val2;
	if (!(ss >> val1)) {
		throw std::invalid_argument("Format input tidak valid! Jumlah jalur harus berupa bilangan bulat.");
	}

	if (ss >> val2) {
		if (val1 != n) {
			throw std::invalid_argument("Jumlah simpul harus " + std::to_string(n) + 
			                           " (titik A sampai E), namun input terbaca: " + std::to_string(val1) + ".");
		}
		m = val2;
	} else {
		m = val1;
	}

	std::string extra_token;
	if (ss >> extra_token) {
		throw std::invalid_argument("Karakter berlebih terdeteksi pada baris pertama: '" + extra_token + "'.");
	}

	if (m < n - 1) {
		throw std::invalid_argument("Jumlah kandidat jalur pipa (m = " + std::to_string(m) + 
		                           ") tidak mencukupi! Minimal diperlukan " + std::to_string(n - 1) + 
		                           " jalur pipa untuk menghubungkan " + std::to_string(n) + " titik.");
	}

	adj_list graph(n);
	char f_raw, s_raw;
	int w;

	std::cout << "\nMasukkan " << m << " data jalur pipa (Format: [Titik1] [Titik2] [Biaya]):\n";
	std::cout << "Contoh: A B 10\n\n";

	for (int i = 0; i < m; i++) {
		std::cout << "Jalur ke-" << (i + 1) << ": ";
		std::string edge_line;

		while (std::getline(std::cin, edge_line)) {
			if (edge_line.find_first_not_of(" \t\r\n") != std::string::npos) break;
		}

		if (edge_line.empty() || edge_line.find_first_not_of(" \t\r\n") == std::string::npos) {
			throw std::runtime_error("Input berakhir sebelum data jalur ke-" + std::to_string(i + 1) + 
			                         " selesai dimasukkan (diharapkan total " + std::to_string(m) + " jalur).");
		}

		std::istringstream iss(edge_line);
		if (!(iss >> f_raw >> s_raw >> w)) {
			throw std::invalid_argument("Format data pada jalur ke-" + std::to_string(i + 1) + 
			                           " salah! Format yang diharapkan: [Titik1] [Titik2] [Biaya].");
		}

		std::string extra_edge_token;
		if (iss >> extra_edge_token) {
			throw std::invalid_argument("Data berlebih pada jalur ke-" + std::to_string(i + 1) + 
			                           ": '" + extra_edge_token + "'. Hanya menerima 3 nilai per baris.");
		}

		char f = toupper(static_cast<unsigned char>(f_raw));
		char s = toupper(static_cast<unsigned char>(s_raw));
		char max_vertex = 'A' + n - 1;

		if (f < 'A' || f > max_vertex || s < 'A' || s > max_vertex) {
			throw std::invalid_argument("Titik tidak valid pada jalur ke-" + std::to_string(i + 1) + 
			                           " ('" + f_raw + "', '" + s_raw + "'). Titik yang diizinkan hanya 'A' sampai '" + 
			                           max_vertex + "'.");
		}

		if (f == s) {
			std::cout << "  -> Peringatan: Jalur menghubungkan titik yang sama (" << f << " ke " << s 
			          << ") dilewati (self-loop).\n";
			continue;
		}

		if (w < 0) {
			throw std::invalid_argument("Biaya pada jalur ke-" + std::to_string(i + 1) + 
			                           " bernilai negatif (" + std::to_string(w) + 
			                           ")! Biaya penggalian dan pipa harus >= 0.");
		}

		graph[f - 'A'].push_back(std::make_pair(s - 'A', w));
	}

	std::vector<edge> result = kruskal(graph);

	if (result.size() < static_cast<size_t>(n - 1)) {
		throw std::runtime_error("Jaringan pipa terputus! Hanya " + std::to_string(result.size()) + 
		                         " dari " + std::to_string(n - 1) + 
		                         " jalur pipa penghubung yang dapat dibentuk. " + 
		                         "Titik-titik utama belum terhubung sepenuhnya menjadi satu jaringan pipa.");
	}

	int total_biaya = 0;
	std::cout << "\n=================================================================\n";
	std::cout << "  REKOMENDASI JARINGAN PIPA INDUK OPTIMAL (MINIMUM SPANNING TREE)\n";
	std::cout << "  (Menghubungkan semua titik dengan biaya minimum & tanpa siklus)\n";
	std::cout << "=================================================================\n";

	for (auto& _edge : result) {
		std::cout << "- Pasang pipa antara Titik " << char(_edge.first + 'A')
		          << " dengan Titik " << char(_edge.second + 'A')
		          << " | Biaya Penggalian & Pipa: Rp " << _edge.weight << "\n";
		total_biaya += _edge.weight;
	}

	std::cout << "-----------------------------------------------------------------\n";
	std::cout << "Total Biaya Penggalian & Pipa Minimum : Rp " << total_biaya << "\n";
	std::cout << "Jumlah Jalur Pipa Terpasang           : " << result.size() << " jalur\n";
	std::cout << "Status: SUKSES! Seluruh 5 titik (A, B, C, D, E) berhasil terhubung.\n";
	std::cout << "=================================================================\n";
}

std::vector<edge> kruskal(const adj_list& graph) {
	if (graph.empty()) {
		throw std::invalid_argument("Graf kosong! Tidak ada data simpul untuk diproses oleh algoritma Kruskal.");
	}

	std::vector<edge> edges, minimum_spanning_tree;
	std::vector<int> pred(graph.size());

	for (size_t i = 0, n = graph.size(); i < n; i++) {
		for (auto& _edge : graph[i])
			edges.push_back( { static_cast<int>(i), _edge.first, _edge.second } );
		pred[i] = static_cast<int>(i);
	}

	auto comp = [&](edge left, edge right) { return left.weight > right.weight; };
	std::sort(edges.begin(), edges.end(), comp);

	while (!edges.empty()) {
		edge shortest = edges.back();
		edges.pop_back();

		int f_head = get_pred(shortest.first, pred);
		int s_head = get_pred(shortest.second, pred);

		if (f_head != s_head) {
			minimum_spanning_tree.push_back(shortest);

			if (f_head < s_head)
				pred[s_head] = f_head;
			else
				pred[f_head] = s_head;
		}
	}

	return minimum_spanning_tree;
}

int get_pred(int vertex, const std::vector<int>& pred) {
	if (vertex < 0 || vertex >= static_cast<int>(pred.size())) {
		throw std::out_of_range("Indeks simpul (" + std::to_string(vertex) + 
		                        ") di luar batas valid pada get_pred().");
	}

	while (pred[vertex] != vertex) {
		vertex = pred[vertex];
		if (vertex < 0 || vertex >= static_cast<int>(pred.size())) {
			throw std::out_of_range("Siklus korup terdeteksi pada penelusuran predecessor.");
		}
	}
	return vertex;
}