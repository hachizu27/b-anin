/**
 * @file main.cpp
 * @brief Program menggunakan beberapa library standar C++.
 *
 * @details
 * Library yang digunakan:
 * - iostream   : Input dan output.
 * - vector     : Penggunaan array dinamis.
 * - utility    : Penggunaan pasangan data (pair).
 * - algorithm  : Operasi algoritma seperti sort.
 * - cctype     : Pengolahan karakter.
 * - string     : Pengolahan teks.
 * - sstream    : Pengolahan string sebagai stream.
 * - stdexcept  : Penanganan pengecualian (exception).
 */


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
#include <stdexcept>

/**
 * @brief Struktur data untuk menyimpan informasi sebuah edge.
 * @details Edge merepresentasikan hubungan antara dua vertex
 * dengan bobot tertentu.
 */

struct edge {
	int first; //vertex pertama
    int second; //vertex kedua
    int weight; //vertex ketiga
};

/**
 * @brief alias tipe data untuk adjacency list pada graf.
 * @details menggunakan vector bersarang yang berisi pair
 * untuk menyimpan vertex tujuan dan bobot edge.
 */

typedef std::vector< std::vector< std::pair<int,int> > > adj_list;

/**
 * @brief menjalankan algoritma Kruskal untuk mencari Minimum Spanning Tree.
 * @param graph Adjacency list yang merepresentasikan graf.
 * @return Kumpulan edge yang membentuk MST.
 */
std::vector<edge> kruskal(const adj_list& graph);

/**
 * @brief get_pred untuk mendapatkan predecessor dari suatu vertex
 * @param vertex untuk membuat simpul
 */
int get_pred(int vertex, const std::vector<int>& pred);

/**
 * @brief menjalankan proses pipeline
 * @details mengatur dan menjalankan tahapan optimasi berdasarkan algoritma yang ditetapkan
 */
void run_pipeline_optimization();

/**
 * @brief fungsi utama untuk menjalankan program
 * @details menjalankan proses optimasi pipeline dan menangani 
 * berbagai jenis exception menggunakan try-catch,
 * untuk menangkap error selama program dijalankan
 * @return 0 jika program berhasil dijalankan, 1 jika terjadi kesalahan
 */
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


/**
 * @brief menjalankan sistem optimasi pipa berdasarkan input dari pengguna
 * @details menampilkan judul sistem optimasi jaringan pipa
 */
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

    /**
     * @brief invalid_argument
     * @details Thrown to report invalid arguments to functions.
     * @details (Dilemparkan untuk melaporkan argumen yang tidak valid pada fungsi)
     * @details jumlah simpul harus maksimal sampai E
     */
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

    /**
     * @brief std::string extra_token
     * @details menjalankan sistem optimasi pipa berdasarkan input dari pengguna
     */
	std::string extra_token;
	if (ss >> extra_token) {
		throw std::invalid_argument("Karakter berlebih terdeteksi pada baris pertama: '" + extra_token + "'.");
	}

	if (m < n - 1) {
		throw std::invalid_argument("Jumlah kandidat jalur pipa (m = " + std::to_string(m) + 
		                           ") tidak mencukupi! Minimal diperlukan " + std::to_string(n - 1) + 
		                           " jalur pipa untuk menghubungkan " + std::to_string(n) + " titik.");
	}

    /**
     * @brief adj_list graph
     * @details sistem optimasi pipa berdasarkan input dari pengguna
     */
	adj_list graph(n);
	char f_raw, s_raw;
	int w;

	std::cout << "\nMasukkan " << m << " data jalur pipa (Format: [Titik1] [Titik2] [Biaya]):\n";
	std::cout << "Contoh: A B 10\n\n";

    /**
     * @brief constexpr std::size_t std::string::find_first_not_of
     * @param (char __c, std::size_t __pos) 
     * @details const noexcept
     *  +4 overloads
     * Find position of a different character.
     * (menemukan karakter yang memiliki posisi berbeda)
     * 
     * 
     * @brief constexpr std::size_t std::vector<edge>::size() const noexcept
     * @details Returns the number of elements in the %vector.
     * 
     * 
     * @brief class std::runtime_error
     * @details Runtime errors represent problems outside the scope of a program; 
     * they cannot be easily predicted and can generally only be caught as the program executes. 
     * One of two subclasses of exception.
     * 
     * 
     * @brief int edge::weight
     * @details vertex ketiga
     */
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

/**
 * @brief std::vector<edge> kruskal(const adj_list &graph)
 * @details menjalankan algoritma Kruskal untuk mencari Minimum Spanning Tree.
 * @param graph – Adjacency list yang merepresentasikan graf.
 * @returns Kumpulan edge yang membentuk MST.
 */

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

    /**
     * @brief int get_pred(int vertex, const std::vector<int> &pred)
     * @details get_pred untuk mendapatkan predecessor dari suatu vertex
     * @param vertex – untuk membuat simpul
     * @return balik ke minimum spanning tree sebelumnya
     */
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

/**
 * @brief int get_pred(int vertex, const std::vector<int> &pred)
 * @details get_pred untuk mendapatkan predecessor dari suatu vertex
 * @param vertex – untuk membuat simpul
 * 
 * @brief class std::out_of_range
 * @details This represents an argument whose value is not within the expected
 * range (e.g., boundary checks in basic_string).
 * untuk mendeteksi batas valid, 
 * jika melapaui, dianggap korup
 * @return vertex
 */

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