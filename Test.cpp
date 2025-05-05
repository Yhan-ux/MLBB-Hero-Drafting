//#include "gtest/gtest.h"
//#include "Hero.h"
//#include "HeroFactory.h"
//
//TEST(HeroTest, TankAttributes) {
//    Tank tank("Tigreal");
//    EXPECT_EQ(tank.getName(), "Tigreal");
//    EXPECT_EQ(tank.getRole(), "Tank");
//}
//
//TEST(HeroTest, MageAttributes) {
//    Mage mage("Lylia");
//    EXPECT_EQ(mage.getName(), "Lylia");
//    EXPECT_EQ(mage.getRole(), "Mage");
//}
//
//TEST(HeroTest, MarksmanAttributes) {
//    Marksman mm("Lesley");
//    EXPECT_EQ(mm.getName(), "Lesley");
//    EXPECT_EQ(mm.getRole(), "Marksman");
//}
//
//TEST(HeroTest, AssassinAttributes) {
//    Assassin assn("Gusion");
//    EXPECT_EQ(assn.getName(), "Gusion");
//    EXPECT_EQ(assn.getRole(), "Assassin");
//}
//
//TEST(HeroTest, SupportAttributes) {
//    Support sup("Estes");
//    EXPECT_EQ(sup.getName(), "Estes");
//    EXPECT_EQ(sup.getRole(), "Support");
//}
//
//TEST(HeroTest, FighterAttributes) {
//    Fighter ftr("Aldous");
//    EXPECT_EQ(ftr.getName(), "Aldous");
//    EXPECT_EQ(ftr.getRole(), "Fighter");
//}
//
//TEST(HeroFactoryTest, CreateValidHeroes) {
//    Hero* tank = HeroFactory::createHero("Tank", "Atlas");
//    ASSERT_NE(tank, nullptr);
//    EXPECT_EQ(tank->getName(), "Atlas");
//    EXPECT_EQ(tank->getRole(), "Tank");
//    delete tank;
//
//    Hero* mage = HeroFactory::createHero("Mage", "Valir");
//    ASSERT_NE(mage, nullptr);
//    EXPECT_EQ(mage->getName(), "Valir");
//    EXPECT_EQ(mage->getRole(), "Mage");
//    delete mage;
//}
//
//TEST(HeroFactoryTest, CreateInvalidHero) {
//    Hero* invalid = HeroFactory::createHero("Dragon", "Shenron");
//    EXPECT_EQ(invalid, nullptr);
//}
//
//TEST(HeroFactoryTest, HeroPoolContainsExpectedRoles) {
//    const auto& pool = HeroFactory::getHeroPool();
//    EXPECT_TRUE(pool.find("Tank") != pool.end());
//    EXPECT_TRUE(pool.find("Mage") != pool.end());
//    EXPECT_TRUE(pool.find("Marksman") != pool.end());
//    EXPECT_TRUE(pool.find("Assassin") != pool.end());
//    EXPECT_TRUE(pool.find("Support") != pool.end());
//    EXPECT_TRUE(pool.find("Fighter") != pool.end());
//}
//
//TEST(HeroFactoryTest, HeroPoolHasNonEmptyHeroesForEachRole) {
//    const auto& pool = HeroFactory::getHeroPool();
//    for (const auto& [role, heroes] : pool) {
//        EXPECT_FALSE(heroes.empty()) << "Role " << role << " has no heroes.";
//    }
//}
