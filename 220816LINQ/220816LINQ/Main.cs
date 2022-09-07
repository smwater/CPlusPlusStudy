using System;
using System.Linq;

namespace OuterJoin
{
    class EquipmentInfo
    {
        public string Name { get; init; }
        public string Ability { get; init; }
    }
    class EquipmentPrice
    {
        public string Name { get; init; }
        public int Price { get; init; }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            EquipmentInfo[] arrInfo =
            {
                new EquipmentInfo(){Name="초보자용 머리쓰개", Ability="물리 방어력 10, 마법 방어력 17"},
                new EquipmentInfo(){Name="재킷", Ability="물리 방어력 33, 마법 방어력 33" },
                new EquipmentInfo(){Name="긴바지", Ability="물리 방어력 33, 마법 방어력 33" },
                new EquipmentInfo(){Name="들장미 장화", Ability="물리 방어력 7, 마법 방어력 13"}
            };

            EquipmentPrice[] arrPrice =
            {
                new EquipmentPrice(){Name="초보자용 머리쓰개", Price=226},
                new EquipmentPrice(){Name="재킷", Price=351 },
                new EquipmentPrice(){Name="긴바지", Price=270 }
            };

            var listEquipment = from info in arrInfo
                                join price in arrPrice on info.Name equals price.Name into e
                                from price in e.DefaultIfEmpty(new EquipmentPrice() { Price = 0 })
                                select new
                                {
                                    Name=info.Name,
                                    Ability=info.Ability,
                                    Price=price.Price,
                                };

            Console.WriteLine("===== 장비 리스트(외부 조인) =====");
            Console.WriteLine("장비이름|\t\t능력치|\t\t가격");
            foreach (var equipment in listEquipment)
            {
                Console.WriteLine($"{equipment.Name}|\t\t{equipment.Ability}|\t\t{equipment.Price}길");
            }
        }
    }
}