#include <vector>
#include <string>
static std::vector<std::string> DB_PATH_DIR = {"Data", "DataBase"};
//=== DATA TYPE ===============================================
using TYPE_DATA = unsigned long long;
//=== PARAMETERS ABOUT CONNECTION =============================
static std::string SERVER_IP = "localhost";
static std::string SERVER_PORT = "5555";
/* COMMANDS */
static std::string COMMAND_SEND_DB = "send_db";
static std::string COMMAND_SUCCESS = "success";
static std::string COMMAND_ACCESS = "access";
//=== PARAMETERS ABOUT ENCRYPTION =============================
#define IV_SIZE 16
const unsigned char ENCRYPT_KEY[IV_SIZE] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};
//=== PARAMETERS ABOUT COLUMN OR ROW ===========================
static bool IS_ROW = true;