package main

import (
	"fmt"
	"os"
	"oscar"
	"testing"
	"time"

	// "strings"
	"database/sql"

	"github.com/stretchr/testify/assert"
	"gorm.io/gorm"
	"gorm.io/gorm/schema"
    "log"
    "io"
)


var (
	Debug   *log.Logger
	Info    *log.Logger
	Warning *log.Logger
	Error   *log.Logger
)

var LogPath string
var LogFile *os.File

func init() {
	logFile, err := os.OpenFile("./log.txt", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	if err != nil {
		log.Fatalln("打开日志文件失败：", err)
	}

	Debug = log.New(io.MultiWriter(os.Stdout, logFile), "Debug:", log.Ldate|log.Ltime|log.Lshortfile)
	Info = log.New(io.MultiWriter(os.Stdout, logFile), "Info:", log.Ldate|log.Ltime|log.Lshortfile)
	Warning = log.New(io.MultiWriter(os.Stdout, logFile), "Warning:", log.Ldate|log.Ltime|log.Lshortfile)
	Error = log.New(io.MultiWriter(os.Stderr, logFile), "Error:", log.Ldate|log.Ltime|log.Lshortfile)
}


var global_db *gorm.DB
var host string
var port string
var user string
var password string
var dbname string

func setup() {
    Debug.Println("setup...")
	host = os.Getenv("host")
	port = os.Getenv("port")
	dbname = os.Getenv("db")
	user = os.Getenv("username")
	password = os.Getenv("password")

	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) //SYSDBA:szoscar55@localhost:2003/OSRDB
	Debug.Println(dsn)
	db, err := gorm.Open(oscar.Open(dsn), &gorm.Config{
		SkipDefaultTransaction: false,
		NamingStrategy: schema.NamingStrategy{
			TablePrefix:   "t_", // 表名前缀，`User`表为`t_users`
			SingularTable: true, // 使用单数表名，启用该选项后，`User` 表将是`user`
		},
		DisableForeignKeyConstraintWhenMigrating: true,
	})
	if err != nil {
		Error.Println(err)
		os.Exit(1)
	}
	global_db = db
}

func tearDown() {
	fmt.Println("tearDown...")
	// Debug.Println("tearDown...")
	// M := global_db.Migrator()
	// M.DropTable(&User{})
	// M.DropTable(&Student{})
}

func TestMain(m *testing.M) {
	setup()
	code := m.Run()
	tearDown()
	os.Exit(code)
}


type User struct {
	Id           uint `gorm:"primaryKey;autoIncrement"` //此处必须是Id,如果是id，建表的时候不能创建该字段
	Name         string
	Email        *string
	Age          uint8 `gorm:"defaut:180"`
	Birthday     *time.Time
	MemberNumber sql.NullString
	ActivatedAt  sql.NullTime
	TestBlob     []byte
	TestByte     byte   //`gorm:"type:byte"`
	TestClob     string `gorm:"type:CLOB"`
	TestString   string

	CreatedAt time.Time `gorm:"autoCreateTime"`
	UpdatedAt time.Time `gorm:"autoUpdateTime"`
}

type Student struct {
	Id        uint      `gorm:"primaryKey;autoIncrement"`
	Name      string    `gorm:"comment:姓名"`
	Age       uint8     `gorm:"defaut:18"`
	CreatedAt time.Time `gorm:"autoCreateTime"`
	UpdatedAt time.Time `gorm:"autoUpdateTime"`
}

type TestColumn struct {
	Id        uint      `gorm:"primaryKey;autoIncrement"`
	Name      string    `gorm:"comment:姓名"`
	Age       uint8     `gorm:"defaut:18"`
	CreatedAt time.Time `gorm:"autoCreateTime"`
	UpdatedAt time.Time `gorm:"autoUpdateTime"`
}

func InsertUsers(users *[]User) int {
	tx := global_db.Create(&users)
	if tx.Error != nil {
		return -1
	} else {
		return int(tx.RowsAffected)
	}
}

func QueryUsers(querySql string) []User {
	var users []User
	global_db.Raw(querySql).Scan(&users)
	return users
}

// AutoMigrate 创建表USERS
func TestCreateTable(t *testing.T) {
	M := global_db.Migrator()
	global_db.AutoMigrate(&User{})
	global_db.AutoMigrate(&TestColumn{})
	r := M.HasTable(&User{})
	r1 := M.HasTable(&TestColumn{})
	assert.Equal(t, r, true)
	assert.Equal(t, r1, true)
}

// CreateTable 创建表
func TestCreateTable2(t *testing.T) {
	M := global_db.Migrator()
	M.CreateTable(&Student{})

	r := M.HasTable(&Student{})
	assert.Equal(t, r, true)
}

func TestRenameTableName(t *testing.T) {
	M := global_db.Migrator()
	if M.HasTable(&Student{}) {
		M.RenameTable(&Student{}, "STUDENTS_NEW")
	} else {
		M.CreateTable(&Student{})
		M.RenameTable(&Student{}, "STUDENTS_NEW")
	}
	r := M.HasTable("STUDENTS_NEW")
	assert.Equal(t, r, true)
	M.RenameTable("STUDENTS_NEW", "STUDENTS")
	r = M.HasTable("STUDENTS")
	assert.Equal(t, r, true)
}

/////////////// 字段操作 /////////////////////
func TestHasColumn(t *testing.T) {
	M := global_db.Migrator()
	r := M.HasColumn(&TestColumn{}, "AGE")
	assert.Equal(t, r, true)
}

func TestDropColumn(t *testing.T) {
	M := global_db.Migrator()
	M.DropColumn(&TestColumn{}, "AGE")
	assert.Equal(t, M.HasColumn(&TestColumn{}, "AGE"), false)
}

func xxTestGetColumnType(t *testing.T) {
	M := global_db.Migrator()
	r, _ := M.ColumnTypes(&TestColumn{}) //([]*sql.ColumnType, error)
	Debug.Println(r)
	fmt.Printf("%T", r)
}

func TestRenameColumn(t *testing.T) {
	M := global_db.Migrator()
	M.RenameColumn(&TestColumn{}, "NAME", "NAME_NEW")
	assert.Equal(t, M.HasColumn(&TestColumn{}, "NAME_NEW"), true)
}

// pass 不知道用法
func xxTestAlterColumn(t *testing.T) {
	M := global_db.Migrator()
	r := M.AlterColumn(&TestColumn{}, "AGE")
	Debug.Println(r)
}

//  pass 不起作用
func xxTestAddColumn(t *testing.T) {
	M := global_db.Migrator()
	r := M.AddColumn(&TestColumn{}, "ADD")
	Debug.Println(r)
}

func TestInsert1(t *testing.T) {
	tx := global_db.Create(&User{Name: "TestInsert1"})
	if tx.Error != nil {
		Info.Println(tx.Error, tx.RowsAffected)
		t.Fatalf("TestInsert1 失败")
	} else {
		Info.Println("插入数据成功")
	}
}

//部分字段
func TestInsert2(t *testing.T) {
	tx := global_db.Select("Name").Create(&User{Name: "golang3"})
	if tx.Error != nil {
		t.Fatalf("TestInsert2 失败")
		} else {
			Info.Println("插入数据成功")
			Info.Println(tx.Error, tx.RowsAffected)
	}
}

// insertBat
func TestInsert3(t *testing.T) {
	tx := global_db.Create(&[]User{
		{Name: "insertBat1", Age: 11},
		{Name: "insertBat1", Age: 12},
		{Name: "insertBat1", Age: 13},
		{Name: "insertBat2", Age: 14},
		{Name: "insertBat3", Age: 20},
		{Name: "insertBat4", Age: 20},
		{Name: "insertBat4", Age: 20},
		{Name: "insertBat4", Age: 20},
		{Name: "insertBat5", Age: 20},
	})
	if tx.Error != nil {
		t.Fatalf("TestInsert3 失败")
		} else {
			Info.Println("插入数据成功", tx.RowsAffected)
			Info.Println(tx.Error, tx.RowsAffected)
	}
}

//Last 用map来接收结果
func TestQuery1(t *testing.T) {
	var result = make(map[string]interface{}) //需把map实例化，否则报nil map 错误
	global_db.Model(&User{}).Last((&result))
	assert.Equal(t, result["NAME"], "insertBat5")

	// Debug.Println(result[1])
}

//Last 用结构体来接收结果
func TestQuery2(t *testing.T) {
	var user User
	global_db.Model(&User{}).Last((&user))
	assert.Equal(t, user.Name, "insertBat5")
}

//Take
func TestQuery3(t *testing.T) {
	var user User
	global_db.Model(&User{}).Take((&user))
	assert.Equal(t, user.Name, "TestInsert1")
}

//Where里嵌入sql语句 查询单条记录
func TestQuery4(t *testing.T) {
	var user User
	global_db.Where("name=?", "insertBat1").First((&user))
	Debug.Println(user)
}

//Where里嵌入结构体 查询单条记录
func TestQuery5(t *testing.T) {
	var user User
	global_db.Where(User{Name: "insertBat1"}).First((&user))
	Debug.Println(user)
}

//Where里嵌入map 查询单条记录
func TestQuery6(t *testing.T) {
	var user User
	global_db.Where(map[string]interface{}{
		"Name": "insertBat1",
	}).First((&user))
	Debug.Println(user)
}

//Where里嵌入map 查询多条记录
func TestQuery7(t *testing.T) {
	var users []User //声明切片来接收结果
	global_db.Where(map[string]interface{}{
		"Name": "insertBat1",
	}).Find((&users))
	assert.Equal(t, len(users), 3)
}

//原生sql 多条
func TestQuery8(t *testing.T) {
	var users []User //声明切片来接收结果
	global_db.Debug().Raw("select * from users").Scan(&users)
	assert.Equal(t, len(users), 11)
}

//原生sql 单条
func TestQuery9(t *testing.T) {
	var user User //声明切片来接收结果
	global_db.Debug().Raw("select * from users where name=?", "insertBat5").Scan(&user).First(&user)
	assert.Equal(t, user.Name, "insertBat5")
}

func TestFirst(t *testing.T) {
	// _users := []User{
	// 	{Name: "TestFirst", Age: 11},
	// 	{Name: "TestFirst", Age: 22},
	// }
	// InsertUsers(&_users)
	// rst := QueryUsers("select * from users where name='TestFirst'")
	// assert.Equal(t, len(rst), 2)

	user := User{}
	global_db.First(&user)
	assert.Equal(t, user.Name, "TestInsert1")

}

func TestLast(t *testing.T) {
	user := User{}
	global_db.Last(&user)
	Debug.Println(user)
	assert.Equal(t, user.Name, "insertBat5")
}

func TestTake(t *testing.T) {
	var user User
	global_db.Model(&User{}).Take(&user)
	Debug.Println(user)
	assert.Equal(t, user.Name, "TestInsert1")
}

// select查询指定字段
func TestSelect(t *testing.T) {
	var user User
	global_db.Debug().Select([]string{"id", "name", "age"}).Where("name = ?", "insertBat5").First(&user)
	Debug.Println(user)
	assert.Equal(t, int(user.Id), 11)
	assert.Equal(t, user.Name, "insertBat5")
	assert.Equal(t, int(user.Age), 20)
	
}

func TestOrder(t *testing.T) {
	var users []User
	// global_db.Where("Created_At >= ?", "2022-03-17 00:00:00").Order("age desc").Find(&users)
	global_db.Where("NAME = ?", "insertBat1").Order("age desc").Find(&users)
	assert.Equal(t, int(users[0].Age), 13)
	assert.Equal(t, int(users[1].Age), 12)
	assert.Equal(t, int(users[2].Age), 11)

}

func TestCount(t *testing.T) {
	var total int64 = 0
	global_db.Model(User{}).Where("age >= ?", "19").Count(&total)
	assert.Equal(t, int(total), 5)
}

//oscar save后数据没变
func xxTestSave(t *testing.T) {
	var user User
	global_db.Where("name = ?", "insertBat5").Take(&user)
	Debug.Println(user)
	user.Name = "insertBatSAVE"
	global_db.Save(&user)
}

func TestLimit(t *testing.T) {
	var users []User
	global_db.Where("name = ?", "insertBat1").Limit(2).Find(&users)
	Debug.Println(users)
	assert.Equal(t, len(users), 2)

}

////////////////分割///////////////////////////

func TestFind(t *testing.T) {
	_users := []User{
		{Name: "TestFind", Age: 11},
		{Name: "TestFind", Age: 11},
		{Name: "TestFind", Age: 11},
	}
	InsertUsers(&_users)

	var users []User
	global_db.Find(&users, "Name=?", "TestFind")
	assert.Equal(t, len(users), 3)
}

// 更新单条记录中的单个字段
func TestUpdate1(t *testing.T) {
	_users := []User{
		{Name: "TestUpdate1", Age: 11}}
	InsertUsers(&_users)
	rst := QueryUsers("select * from users where name='TestUpdate1' and age=11")
	assert.Equal(t, len(rst), 1)

	var user User
	global_db.Debug().Where(User{Name: "TestUpdate1"}).First(&user).Update("Name", "TestUpdate1-single-column")
	assert.Equal(t, user.Name, "TestUpdate1-single-column")
}

// 更新单条记录中的多个字段
func TestUpdate2(t *testing.T) {
	_users := []User{
		{Name: "myTestUpdate2", Age: 11}}
	InsertUsers(&_users)
	rst := QueryUsers("select * from users where name='myTestUpdate2' and age=11")
	assert.Equal(t, len(rst), 1)

	var user User
	tx := global_db.Debug().Where(User{Name: "myTestUpdate2"}).First(&user).Updates(User{Name: "TestUpdate2-many-column", Age: 99})
	Debug.Println(tx.Error, tx.RowsAffected)
	assert.Equal(t, user.Name, "TestUpdate2-many-column")
	assert.Equal(t, int(user.Age), 99)
}

// 更新多条记录中的多个字段
func TestUpdate3(t *testing.T) {
	_users := []User{
		{Name: "TestUpdate3", Age: 12},
		{Name: "TestUpdate3", Age: 12},
		{Name: "TestUpdate3", Age: 12},
		{Name: "TestUpdate3", Age: 12},
	}
	InsertUsers(&_users)
	rst := QueryUsers("select * from users where name='TestUpdate3' and age=12")
	assert.Equal(t, len(rst), 4)

	var users []User
	tx := global_db.Debug().Where(User{Name: "TestUpdate3"}).Updates(User{Name: "TestUpdate3-bat", Age: 98})
	Debug.Println(tx.Error, tx.RowsAffected)
	assert.Equal(t, int(tx.RowsAffected), 4)

	global_db.Debug().Where(User{Name: "TestUpdate3-bat", Age: 98}).Find(&users)
	assert.Equal(t, len(users), 4)

}

// 事务
func TestTransaction(t *testing.T) {
	tx := global_db.Begin()
	if err := tx.Create(&User{Name: "Transaction"}).Error; err != nil {
		tx.Rollback()
		t.Fatalf("TestTransaction 失败")
	}
	tx.Commit()

	var users []User
	global_db.Debug().Where(User{Name: "Transaction"}).Find(&users)
	assert.Equal(t, len(users), 1)
}

// 删除模型数据
// 删除模型数据一般用于删除之前查询出来的模型变量绑定的记录。
// 用法：db.Delete(模型变量)
// 不起作用 无法删除 ?????
func TestDelete1(t *testing.T) {
	_users := []User{
		{Name: "TestDelete1", Age: 12},
	}
	InsertUsers(&_users)
	rst := QueryUsers("select * from users where name='TestDelete1' and age=12")
	assert.Equal(t, len(rst), 1)

	var user User
	global_db.Where("Name = ?", "TestDelete1").Take(&user)
	global_db.Delete(&user)

	rst = QueryUsers("select * from users where name='TestDelete1' and age=12")
	assert.Equal(t, len(rst), 0)

}

// 根据Where条件删除数据
// 用法：db.Where(条件表达式).Delete(空模型变量指针)
func TestDelete2(t *testing.T) {
	_users := []User{
		{Name: "TestDelete2", Age: 12},
		{Name: "TestDelete2", Age: 12},
		{Name: "TestDelete2", Age: 12},
	}
	InsertUsers(&_users)
	rst := QueryUsers("select * from users where name='TestDelete2' and age=12")
	assert.Equal(t, len(rst), 3)

	global_db.Where("Name = ?", "TestDelete2").Delete(&User{})
	rst = QueryUsers("select * from users where name='TestDelete2' and age=12")
	assert.Equal(t, len(rst), 0)
}
